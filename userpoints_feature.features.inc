<?php
/**
 * @file
 * userpoints_feature.features.inc
 */

/**
 * Implements hook_node_info().
 */
function userpoints_feature_node_info() {
  $items = array(
    'news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}