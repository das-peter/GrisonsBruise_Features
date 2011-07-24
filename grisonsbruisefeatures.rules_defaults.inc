<?php
/**
 * @file
 * grisonsbruisefeatures.rules_defaults.inc
 */

/**
 * Implementation of hook_default_rules_configuration().
 */
function grisonsbruisefeatures_default_rules_configuration() {
  $items = array();
  $items['rules_add_paid_membership_fee'] = entity_import('rules_config', '{ "rules_add_paid_membership_fee" : {
      "LABEL" : "Add paid membership fee",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "user" : { "label" : "Benutzer", "type" : "user" },
        "year" : { "label" : "Jahr", "type" : "taxonomy_term" },
        "paid" : { "label" : "Bezahlt", "type" : "boolean" }
      },
      "IF" : [ { "data_is" : { "data" : [ "paid" ], "value" : 1 } } ],
      "DO" : [
        { "list_add" : {
            "list" : [ "user:field-membership-paid" ],
            "item" : [ "year" ],
            "unique" : 1
          }
        }
      ]
    }
  }');
  $items['rules_membership_fee_paid'] = entity_import('rules_config', '{ "rules_membership_fee_paid" : {
      "LABEL" : "Mitgliederbeitrag bezahlt",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "users" : { "label" : "Benutzer", "type" : "list\\u003cuser\\u003e" },
        "year" : { "label" : "Jahr", "type" : "taxonomy_term" },
        "paid" : { "label" : "Bezahlt", "type" : "boolean" }
      },
      "ACTION SET" : [
        { "LOOP" : {
            "USING" : { "list" : [ "users" ] },
            "ITEM" : { "current_user" : "Aktueller Benutzer" },
            "DO" : [
              { "component_rules_add_paid_membership_fee" : { "user" : [ "current-user" ], "year" : [ "year" ], "paid" : [ "paid" ] } },
              { "component_rules_remove_paid_membership_fee" : { "user" : [ "current-user" ], "year" : [ "year" ], "paid" : [ "paid" ] } },
              { "entity_save" : { "data" : [ "current-user" ] } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_remove_paid_membership_fee'] = entity_import('rules_config', '{ "rules_remove_paid_membership_fee" : {
      "LABEL" : "Remove paid membership fee",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "user" : { "label" : "Benutzer", "type" : "user" },
        "year" : { "label" : "Jahr", "type" : "taxonomy_term" },
        "paid" : { "label" : "Bezahlt", "type" : "boolean" }
      },
      "IF" : [ { "data_is" : { "data" : [ "paid" ], "value" : 0 } } ],
      "DO" : [
        { "list_remove" : { "list" : [ "user:field-membership-paid" ], "item" : [ "year" ] } }
      ]
    }
  }');
  return $items;
}
