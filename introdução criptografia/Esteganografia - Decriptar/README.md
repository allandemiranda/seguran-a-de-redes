Atividade Prática - Esteganografia - Decriptar

Desenvolvido  por [Allan de Miranda](https://github.com/allandemiranda)

14 de agosto de 2019 - Segurança de Redes - IMD

## Introdução

Escreva um programa que lê uma mensagem e a esconda em um arquivo de imagem
no formato Bitmap (um dos formatos mais utilizados na esteganografia pelo fato de não
possuir compactação) e outro que permita extrair a mensagem do arquivo novamente.
― Técnica de ocultação: A cada 3 pixels da imagem, composto por 3 bytes cada (RGB), têm-se 9 bytes
― Desses 9 bytes, pegar o bit menos significativo dos 8 primeiros e ocultar os bits de caractere da mensagem (char = 8 bits).
― Testar se a imagem comporta a mensagem!
― Detalhes do formato Bitmap pode ser aprendido em http://tipsandtricks.runicsoft.com/Cpp/BitmapTutorial.html ou numa simples consulta ao Google!
― Teste o seu programa com o algum colega (e vice-versa).

## Instalação

Para instalar e executar o programa siga as instruções:

1. Abra o terminal do seu sistema operacional e digite `cd`
2. `git clone https://github.com/allandemiranda/seguran-a-de-redes.git`
3. `cd seguran-a-de-redes/introdução\ criptografia/Esteganografia\ -\ Decriptar/`
4. `make`

## Como utilizar

1. Adicione a mensagem no arquivo 'mensagem.txt' da pasta '/data'.

2. Certifique-se que não existem arquivos na pasta '/result'.

2. Execulte o programa: 

Abra o terminal do seu sistema operacional e digite 

`cd`

`cd seguran-a-de-redes/introdução\ criptografia/Esteganografia\ -\ Decriptar/`

`./bin/main.o X`

Onde 'X' corresponde ao caminho do arquivo de imagem de formato .bmp que deseja decriptar a mensagem

3. Aguarde até o programa exibir a mensagem de "Mensagem Decriptada na Imagem".

4. Verifique o resultado da imagem em 'result/keyMsg.txt'
