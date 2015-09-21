{
  "targets": [
    {
      "target_name": "GraphQLParser",
      "sources": [ "GraphQLParser.cc", "functions.cc" ],
      "include_dirs" : [
 	 			"<!(node -e \"require('nan')\")"
			],
		  "cflags": [
		    "-std=c++11",
			  "-stdlib=libc++"
			],
      "conditions": [
        [ 'OS=="mac"', {
          "xcode_settings": {
            'OTHER_CPLUSPLUSFLAGS' : ['-std=c++11','-stdlib=libc++'],
            'OTHER_LDFLAGS': ['-stdlib=libc++'],
            'MACOSX_DEPLOYMENT_TARGET': '10.7'
          }
        }]
      ]
    }
  ]
}
