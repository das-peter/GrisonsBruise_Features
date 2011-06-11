<?php
/**
 * @file
 * grisonsbruisefeatures.features.taxonomy.inc
 */

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function grisonsbruisefeatures_taxonomy_default_vocabularies() {
  return array(
    'mitgliederbeitr_ge' => array(
      'name' => 'Mitgliederbeiträge',
      'machine_name' => 'mitgliederbeitr_ge',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
