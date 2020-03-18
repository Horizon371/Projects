#pragma once
#include <QAbstractTableModel>
#include "Controller.h"

class Model :
	public QAbstractTableModel
{
private:
	Controller &controller;

public:
	Model(Controller &c);
	~Model();

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;
	//bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
	Qt::ItemFlags flags(const QModelIndex &index) const override;
};

