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

# Listagens 
> $ docker ps
- Lista todos os containers rodando atualmente
- A lista traz as informações de cada container
> $ docker ps -a
- Lista todos os containers criados na máquina, inclusive os que estão com status "exited" (antes ocultos)
>

# Parar um container
> $ docker stop nome-do-container (ou id do container)

# Iniciar um container já existente
> $ docker start nome-do-container (ou id do container)

# Baixar uma imagem sem criar container
> $ docker pull nome-da-imagem

# Remover um container da máquina
> $ docker rm(ou remove) nome-do-container (ou id do container)
- Somente containers parados podem ser removidos
- Uma vez removidos não podem ser recuperados

# Entrar no container em modo Bash
> $ docker exec -it nome-do-container (ou id do container) bash

# Verificação de logs
> $ docker logs nome-do-container (ou id do container)
- Mostra os ultimos logs do container
> $ docker logs -f nome-do-container (ou id do container)
- O terminal continua mostrando os logs do container em tempo real até que receba um comando de parada ou seja fechado

