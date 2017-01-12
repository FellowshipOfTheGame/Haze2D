# Haze2D
Haze2D é uma biblioteca de desenvolvimento de jogos 2D construída por cima da [SFML](https://www.sfml-dev.org/) (Simple and Fast Multimedia Library). A game engine foi feita pelos membros do grupo Fellowship of the Game do Instituto de Ciências Matemáticas e de Computação da Universidade de São Paulo. A biblioteca é voltada ao aprendizado do alunos da disciplina de jogos e para o uso geral do grupo.

## Compilação
A biblioteca faz uso da SFML 2.x.x e, para a compilação, é necessário ter instalado a biblioteca disponível no site oficial ou da compilação da mesma. Além disso é precisso [CMake](http://cmake.org/) que gerará os arquivos de projeto. Caso o CMake não encontre as bibliotecas instaladas no computador, ele tentará compilar a biblioteca diretamente do repositório. Para isso são necessários os seguintes procedimentos:
* Clone o projeto usando, adcionando a opção `--recursive` para a compilação junto com o SFML.
* Dentro da pasta do repositório clonado:
```
mkdir build
cd build
cmake ..
make
```

Note que para a compilação juntamente com a SFML são necessários os pacotes especificados no site oficial:
* freetype
* jpeg
* x11
* xrandr
* xcb
* x11-xcb
* xcb-randr
* xcb-image
* opengl
* flac
* ogg
* vorbis
* vorbisenc
* vorbisfile
* openal
* pthread
