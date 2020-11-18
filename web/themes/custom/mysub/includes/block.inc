<?php

/**
 * @file
 * Theme and preprocess functions for blocks.
 */

/**
 *
 */
function mysub_theme_suggestions_block_alter(array &$suggestions, array $variables) {
  if (isset($variables['elements']['content']['#block_content'])) {
    array_splice($suggestions, 1, 0, 'block__' . $variables['elements']['content']['#block_content']->bundle());
  }
}

/**
 *
 */
function mysub_preprocess_block(&$variables) {
  // Adding custom attribute class for block.
  if ($variables['elements']['#base_plugin_id'] == 'block_content') {
    $blockType = strtr($variables['content']['#block_content']->bundle(), '_', '-');
    $variables['attributes']['class'][] = 'block--type-' . $blockType;
  }
}
