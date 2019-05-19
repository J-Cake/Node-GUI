{
  "targets": [{
      "target_name": "node_gui",
      "sources": [ "source/entry.cpp", "source/renderer.cpp", "source/CreateWindow.cpp", "source/Colour.cpp", "source/draw.cpp", "source/STDFuncs.cpp" ],
      "include_dirs": ["headers"],
      "libraries": ["d2d1.lib"]
    }]
}