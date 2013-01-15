<?php
/**
 * @file
 * userpoints_feature.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function userpoints_feature_default_rules_configuration() {
  $items = array();
  $items['rules_userpoint_for_comment'] = entity_import('rules_config', '{ "rules_userpoint_for_comment" : {
      "LABEL" : "Userpoint for comment",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "userpoints" ],
      "REQUIRES" : [ "rules", "userpoints_rules", "comment" ],
      "ON" : [ "comment_insert" ],
      "IF" : [
        { "AND" : [
            { "node_is_of_type" : {
                "node" : [ "comment:node" ],
                "type" : { "value" : { "news" : "news" } }
              }
            },
            { "NOT data_is" : { "data" : [ "comment:author" ], "value" : [ "comment:node:author" ] } }
          ]
        }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "comment:node:author" ],
            "points" : "1",
            "tid" : "0",
            "entity" : [ "" ],
            "operation" : "Insert",
            "display" : 1,
            "moderate" : "default"
          }
        }
      ]
    }
  }');
  $items['rules_userpoint_for_content'] = entity_import('rules_config', '{ "rules_userpoint_for_content" : {
      "LABEL" : "Userpoint for content",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "userpoints" ],
      "REQUIRES" : [ "rules", "userpoints_rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "news" : "news" } } } }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "3",
            "tid" : "0",
            "entity" : [ "" ],
            "operation" : "Insert",
            "display" : 1,
            "moderate" : "default"
          }
        }
      ]
    }
  }');
  return $items;
}
