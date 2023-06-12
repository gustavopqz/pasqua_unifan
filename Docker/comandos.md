# Criação de container
> $ docker run nome-da-imagem
- Caso não haja a imagem na máquina o docker vai ao dockerhub e realiza download da imagem
- Já com a imagem na máquina é criado um container com aquela imagem
- No caso caso não sejam passados os parâmetros como porta, nome do container, volumes, variáveis de ambiente, o container é criado seguindo default

> $ docker run -it nome-da-imagem bash
- Faz o mesmo do docker run simples porém inicia o projeto em modo bash
- O modo bash faz o projeto interpretar comandos linux

> $ docker run -d nome-da-imagem
- Cria o container em segundo plano
- Continua rodando até que receba um comando para parar
- Caso não utilize o comando -d, não podemos fechar ou utilizar o cmd em que este container foi rodado

> $ docker run --name nome-do-meu-container -p porta-na-minha-maquina:porta-interna-no-container -v caminho-da-minha-pasta:caminho-da-pasta-no-container -e nome-da-variavel-de-ambiente=valor-da-variavel -d nome-da-imagem
- Exemplo de docker run com parametros

> $ docker create nome-da-imagem
- Cria o container mas ele não está rodando
- Possível visualizar com listagem de todos os containers

> OBS: docker run == docker create + docker start

# Listagem de containers
> $ docker ps
- Lista todos os containers rodando atualmente
- A lista traz as informações de cada container
> $ docker ps -a
- Lista todos os containers criados na máquina, inclusive os que estão com status "exited" (antes ocultos)

# Start e stop
> $ docker stop nome-do-container (ou id do container)
- Para um container que está rodando
> $ docker start nome-do-container (ou id do container)
- Inicia um container existente na máquina que está parado

# Remover um container da máquina
> $ docker rm(ou remove) nome-do-container (ou id do container)
- Somente containers parados podem ser removidos
- Uma vez removidos não podem ser recuperados

# Informações de container
> $ docker inspect nome-do-container (ou id do container)
- Mostra informações gerais do container solicitado

# Entrar no container em modo Bash
> $ docker exec -it nome-do-container (ou id do container) bash

# Verificação de logs
> $ docker logs nome-do-container (ou id do container)
- Mostra os ultimos logs do container
> $ docker logs -f nome-do-container (ou id do container)
- O terminal continua mostrando os logs do container em tempo real até que receba um comando de parada ou seja fechado

# Imagens
> $ docker images
- Lista todas as imagens presentes na máquina
> $ docker pull nome-da-imagem
- Baixa uma imagem sem criar um container
> $ docker rmi id-da-imagem(ou nome no repositório)
- Remove a imagem da máquina
> $ docker push nome-da-imagem
- Enviar uma imagem da máquina a um repositório (necessário estar logado => $ docker login)

# Cópia de arquivo ou pasta
> docker cp path-atual:path-futuro
- Funciona tanto da máquina host para o container quanto o inverso

# Rede
> $ docker network create nome-da-rede
- Para adicionar containers a uma nova rede pare que eles possam se enxergar entre si podemos utilizar a rede padrão ou criar uma nova
- No comando docker a rede pode ser passada como $ docker run -network nome-da-rede nome-da-imagem
> $ docker network prune
- Remove todas as networks da máquina host que não estão sendo utlizadas
> $ docker network rm nome-da-rede
- Romove uma rede específica

# Volume
> $ docker volume ls
- Lista todos os volumes
