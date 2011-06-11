<?php
/**
 * @file
 * grisonsbruisefeatures.features.field.inc
 */

/**
 * Implementation of hook_field_default_fields().
 */
function grisonsbruisefeatures_field_default_fields() {
  $fields = array();

  // Exported field: 'user-user-field_address'
  $fields['user-user-field_address'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_address',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'addressfield',
      'settings' => array(),
      'translatable' => '1',
      'type' => 'addressfield',
    ),
    'field_instance' => array(
      'bundle' => 'user',
      'default_value' => array(
        0 => array(
          'administrative_area' => '',
          'country' => 'CH',
          'dependent_locality' => '',
          'element_key' => 'user|user|field_address|und|0',
          'first_name' => '',
          'last_name' => '',
          'locality' => '',
          'organisation_name' => '',
          'postal_code' => '',
          'premise' => '',
          'thoroughfare' => '',
          'xal' => '',
          'xnl' => '<NameDetails/>
',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'addressfield',
          'settings' => array(),
          'type' => 'addressfield_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'user',
      'field_name' => 'field_address',
      'label' => 'Adresse',
      'required' => 0,
      'settings' => array(
        'user_register_form' => 1,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'addressfield',
        'settings' => array(
          'available_countries' => array(),
          'name_format' => 'first_last_organisation',
        ),
        'type' => 'addressfield_standard',
        'weight' => '31',
      ),
    ),
  );

  // Exported field: 'user-user-field_membership_paid'
  $fields['user-user-field_membership_paid'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_membership_paid',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'mitgliederbeitr_ge',
          ),
        ),
      ),
      'translatable' => '1',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'user',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 1,
        ),
      ),
      'entity_type' => 'user',
      'field_name' => 'field_membership_paid',
      'label' => 'Mitgliederbeitrag bezahlt',
      'required' => 0,
      'settings' => array(
        'user_register_form' => 0,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '32',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Adresse');
  t('Mitgliederbeitrag bezahlt');

  return $fields;
}
