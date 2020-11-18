<?php

/**
 * @file
 * Theme and preprocess functions for nodes.
 */

/**
 *
 */
function mysub_preprocess_node(&$variables) {
    /** @var \Drupal\node\NodeInterface $node */
    $node = $variables['node'];

    $variables['is_front'] = \Drupal::service('path.matcher')->isFrontPage();
    $langCode = \Drupal::languageManager()->getCurrentLanguage()->getId();
    $variables['language'] = $langCode;
    // Provide an array of language objects, so that we can build language
    // sensitive URLs in Twig.
    // Can be simplified once
    // https://www.drupal.org/project/drupal/issues/2363459 lands in.
    $variables['languages'] = \Drupal::languageManager()->getLanguages();
}
