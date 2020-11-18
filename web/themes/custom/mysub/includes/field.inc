<?php

/**
 * @file
 * Theme and preprocess functions for fields.
 */

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 * Adding view modes suggestion as well.
 */
function mysub_theme_suggestions_field_alter(&$suggestions, $variables) {
  $suggestions[] = 'field__' . $variables['element']['#entity_type'] . '__' . $variables['element']['#field_name'] . '__' . $variables['element']['#bundle'] . '__' . $variables['element']['#view_mode'];
}
