 { pkgs ? import <nixpkgs> {} }:
 
 (pkgs.buildFHSUserEnv {
   name = "bazel-userenv-example";
   targetPkgs = pkgs: [
     pkgs.bazel
     pkgs.glibc
     pkgs.gcc
   ];
 }).env
