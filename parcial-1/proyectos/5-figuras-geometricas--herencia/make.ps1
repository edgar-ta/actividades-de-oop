function make-dependencies() {
  remove-item ./bin/*;
  ls ./header | % {
    $object_name = $_.name -replace ".h$","";
    g++ -c "./src/$object_name.cpp" -o "./bin/$object_name.o"
  }
}

function make-executable() {
  make-dependencies;
  g++ main.cpp ./bin/* -o "./main.exe";
}

