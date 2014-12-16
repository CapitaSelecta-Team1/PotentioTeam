OSGI
====

 - Check the code base on your node with `getCodebaseIDs nodeXY`. Check this number corresponds to your configuration.
 - Instantiate each code base with `Instantiate codebaseid nodeXY` this returns an id.
 - Wire components together on the node by event id and component id with `wirelocal event_id nodeid nodeid nodeXY`
 - Activate the different components with `Activate id nodeXY'
