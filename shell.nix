with import <nixpkgs> {};

mkShell {
  nativeBuildInputs = [ pkg-config cmake ];
  buildInputs = [ curl boost ];
}
