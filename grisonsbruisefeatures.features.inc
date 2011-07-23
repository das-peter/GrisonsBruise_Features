<?php
/**
 * @file
 * grisonsbruisefeatures.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function grisonsbruisefeatures_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_views_api().
 */
function grisonsbruisefeatures_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
