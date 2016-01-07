{
  'targets': [
    {
      'target_name': 'binding',
      'sources': [ 'binding.cpp' ],
      "include_dirs" : [
          "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}