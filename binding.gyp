{
  'targets': [
    {
      'target_name': 'binding',
      'sources': [ 'src-binding/binding.cpp' ],
      "include_dirs" : [
          "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}