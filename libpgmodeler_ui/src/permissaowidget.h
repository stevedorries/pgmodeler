/*
# PostgreSQL Database Modeler (pgModeler)
#
# Copyright 2006-2013 - Raphael Araújo e Silva <rkhaotix@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation version 3.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# The complete text of GPLv3 is at LICENSE file on source code root directory.
# Also, you can get the complete GNU General Public License at <http://www.gnu.org/licenses/>
*/

/**
\ingroup libpgmodeler_ui
\class PermissaoWidget
\brief Definição da classe que implementa o formulário de edição dos atributos de permissões de objetos.
*/

#ifndef PERMISSAO_WIDGET_H
#define PERMISSAO_WIDGET_H

#include "baseobjectwidget.h"
#include "ui_permissaowidget.h"
#include "tabelaobjetoswidget.h"
#include "visaoobjetoswidget.h"

class PermissaoWidget: public BaseObjectWidget, public Ui::PermissaoWidget {
		Q_OBJECT

	private:
		//! \brief Armazena a permissão selecionada atualmente para edição
		Permission *permissao;

		//! \brief Conteineres de papéis e de permissões
		TabelaObjetosWidget *tab_papeis, *tab_permissoes;

		VisaoObjetosWidget *selecaoobjetos_wgt;

	public:
		PermissaoWidget(QWidget * parent = 0);
		~PermissaoWidget(void);
		void setAttributes(DatabaseModel *model, BaseObject *objeto_pai, BaseObject *object);

	private slots:
		//! \brief Exibe a janela de seleção de objetos do modelo
		void selecionarPapel(void);

		//! \brief Seleciona uma permissão cujo índice é especificado no parâmetro
		void selecionarPermissao(int idx_perm);

		//! \brief Adiciona ao modelo a permissão configurada no formulário
		void adicionarPermissao(void);

		/*! \brief Método de configuração de uma permissão. Este método
			faz a atribuição dos valores preenchidos no formulário
				permissão do parâmetro. Este método é compartilhado
			entre as ações de adição e atualização de permissão */
		void configurarPermissao(Permission *permissao);

		/*! \brief Preenche o formulário com os dados da permissão selecionada
			na tabela de permissões para uma posterior edição */
		void editarPermissao(void);

		//! \brief Remove a permissão selecionada na tabela de permissões
		void removerPermissao(void);

		//! \brief Remove todas as permissões da tabela de permissão
		void removerPermissoes(void);

		//! \brief Atualiza os dados da permissão atualmente em edição
		void atualizarPermissao(void);

		//! \brief Lista todas as permissões relacionadas ao objeto atual
		void listarPermissoes(void);

		/*! \brief Cancela a operação de criação/edição de uma permissão
			limpando o formulário e bloqueando os botões relacionados */
		void cancelarOperacao(void);

		//! \brief Exibe os dados do papel selecionado na tabela de papéis
		void exibirDadosPapelSelecionado(void);

		/*! \brief Habilita ou desabilita os botões de edição com base
			nos dados preenchidos ou não no formulário */
		void habilitarBotoesEdicao(void);

		/*! \brief Selecionao checkbox relacionados a um privilégio na
			tabela de privilégios */
		void marcarPrivilegio(void);

	public slots:
		void hideEvent(QHideEvent *);
};

#endif
