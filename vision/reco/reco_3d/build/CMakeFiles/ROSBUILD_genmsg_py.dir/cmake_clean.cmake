FILE(REMOVE_RECURSE
  "../msg_gen"
  "../src/reco_3d/msg"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/reco_3d/msg/__init__.py"
  "../src/reco_3d/msg/_OBBArray.py"
  "../src/reco_3d/msg/_StringArray.py"
  "../src/reco_3d/msg/_OBB.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
