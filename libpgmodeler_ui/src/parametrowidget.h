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
\class ParametroWidget
\brief Definição da classe que implementa o formulário de edição de parâmetro de funções.
*/

#ifndef PARAMETRO_WIDGET_H
#define PARAMETRO_WIDGET_H

#include "baseobjectwidget.h"
#include "ui_parametrowidget.h"
#include "tipopgsqlwidget.h"

class ParametroWidget: public BaseObjectWidget, public Ui::ParametroWidget {
		Q_OBJECT

	private:
		TipoPgSQLWidget *tipo_pgsql;

		//! \brief Armazena a cópia do parâmetro configurado
		Parameter parametro;

	public:
		ParametroWidget(QWidget * parent = 0);
		void setAttributes(Parameter parametro, DatabaseModel *model);

		/*! \brief Retorna a cópia do parâmetro configurado. Este método deve
			ser usado para se ter acesso ao parâmetro configurado */
		Parameter obterParametro(void);

	private slots:
		void hideEvent(QHideEvent *);

	public slots:
		void applyConfiguration(void);
};

#endif
