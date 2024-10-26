# Tabela de Gastos

Este projeto é um programa em C para registrar e gerenciar despesas pessoais em um arquivo CSV. Ele permite criar uma tabela de gastos com data, tipo, descrição e valor, facilitando o controle financeiro.

## Funcionalidades

- **Registro de Despesas**: Permite registrar cada despesa com data, categoria, descrição e valor.
- **Categorias Predefinidas**: Inclui nove categorias para despesas comuns, como Moradia, Alimentação e Educação.
- **Armazenamento em CSV**: Salva os dados em formato CSV, permitindo visualização e análise fácil em programas de planilhas.

## Pré-requisitos

Para compilar e executar o programa, você precisa de um compilador C, como `gcc`.

## Estrutura dos Dados

Cada despesa é armazenada com os seguintes campos:

- `date`: Data da despesa, no formato "dd/mm/aaaa".
- `category`: Um número entre 1 e 9 indicando a categoria da despesa.
- `description`: Descrição breve da despesa, com até 300 caracteres.
- `amount`: Valor da despesa (use vírgula `,` para separar as casas decimais, se aplicável).

## Como Usar

1. Clone o repositório e navegue até o diretório do projeto:

   ```bash
   git clone https://github.com/mhfmedeiros/expense_table_update.git
   cd expense_table

