<?php
/**
 * @file
 * grisonsbruisefeatures.features.user_role.inc
 */

/**
 * Implementation of hook_user_default_roles().
 */
function grisonsbruisefeatures_user_default_roles() {
  $roles = array();

  // Exported role: Vereinsmitglied
  $roles['Vereinsmitglied'] = array(
    'name' => 'Vereinsmitglied',
    'weight' => '3',
  );

  // Exported role: Vorstandsmitglied
  $roles['Vorstandsmitglied'] = array(
    'name' => 'Vorstandsmitglied',
    'weight' => '4',
  );

  return $roles;
}
