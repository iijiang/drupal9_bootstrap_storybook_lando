<?php

/**
 * @file
 * Theme and preprocess functions for pages.
 */

/**
 * Adds theme path alias suggestion for use in system pages bundle.
 */
use Drupal\taxonomy\Entity\Term;
use Drupal\node\NodeInterface;

function mysub_theme_suggestions_page_alter(array &$suggestions, array $variables) {
  $current_path = \Drupal::service('path.current')->getPath();
  $result = \Drupal::service('path_alias.manager')->getAliasByPath($current_path);

  $path_alias = trim($result, '/');
  $path_alias = str_replace('/', '-', $path_alias);
  $path_alias = str_replace('-', '_', $path_alias);

  $suggestions[] = 'page__path__' . $path_alias;

  // Defines custom theme suggestions based on the route.
  $route_name = \Drupal::request()->attributes->get('_route');
  if ('system.404' === $route_name) {
    $suggestions[] = 'page__404';
  }
  if ('system.403' === $route_name) {
    $suggestions[] = 'page__403';
  }

  // * Adds page node type theme suggestion.
  if ($node = \Drupal::routeMatch()->getParameter('node')) {
    if ($node_revision = \Drupal::routeMatch()->getParameter('node_revision')) {
      if ($node_revision = \Drupal::entityTypeManager()->getStorage('node')->loadRevision($node_revision)) {
        $node = $node_revision;
      }
    }
    if ($node instanceof NodeInterface) {
      $suggestions[] = 'page__node__' . $node->getType();
    }
  }

  // * Add view mode theme suggestions based on the vocabulary
  if (\Drupal::routeMatch()->getRouteName() == 'entity.taxonomy_term.canonical' && $tid = \Drupal::routeMatch()->getRawParameter('taxonomy_term')) {
    $term = Term::load($tid);
    $suggestions[] = 'page__taxonomy__' . $term->getVocabularyId();
  }
}
