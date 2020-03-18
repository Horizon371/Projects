#include "Model.h"
#include "qcolor.h"

Model::Model(Controller &c) : controller{ c }
{
}


Model::~Model()
{
}

int Model::rowCount(const QModelIndex & parent) const
{
	return this->controller.getArrayFRomRepository().size();
}

int Model::columnCount(const QModelIndex & parent) const
{
	return 5;
}

QVariant Model::data(const QModelIndex & index, int role) const
{
	int row = index.row();
	int col = index.column();
	Material currentMaterial = this->controller.getArrayFRomRepository()[row];

	if (role == Qt::DisplayRole)
	{
		switch (col)
		{
		case 0:
			return QString::fromStdString(currentMaterial.getId());
		case 1:
			return QString::fromStdString(currentMaterial.getSize());
		case 2:
			return QString::number(currentMaterial.getRadioactivityLevel());
		case 3:
			return QString::number(currentMaterial.getQuantityOfMicrofragments());
		case 4:
			return QString::fromStdString(currentMaterial.getDigitizedScan());
		default:
			break;
		}
	}

	if (role == Qt::BackgroundRole)
		if (row % 2 == 0)
			return QColor{ Qt::green };

	return QVariant();
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
	{
		switch (section)
		{
		case 0:
			return "Id";
		case 1:
			return "Size";
		case 2:
			return "Radioactivity level";
		case 3:
			return "Quantity of microfragments";
		case 4:
			return "Digitized scan";

		default:
			break;
		}
	}

	return QVariant();
}

//bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role)
//{	
//	Material& currentMaterial = this->controller.getArrayFRomRepository()[index.row()];
//
//	if (role == Qt::EditRole)
//	{
//		switch (index.column())
//		{
//		case 0:
//			currentMaterial.setName(value.toString().toStdString());
//			break;
//		case 1:
//			currentMaterial.setGroup(value.toString().toStdString());
//			break;
//		case 2:
//			currentMaterial.setLabGrade(value.toString().toDouble());
//			break;
//		case 3:
//			currentMaterial.setSeminarGrade(value.toString().toDouble());
//			break;
//		default:
//			break;
//		}
//	}
//
//	emit dataChanged(index, index);
//
//	return true;
//}

Qt::ItemFlags Model::flags(const QModelIndex & index) const
{
	return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}
