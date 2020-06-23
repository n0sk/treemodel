#ifndef TREEMODEL_H
#define TREEMODEL_H
#include <QAbstractItemModel>
class TreeItem;

class TreeModel : public QAbstractItemModel
{
public:
    TreeModel(QObject* parent);
    ~TreeModel();
    Q_INVOKABLE QModelIndex index(int row, int column,
                              const QModelIndex &parent = QModelIndex()) const  override;
    Q_INVOKABLE QModelIndex parent(const QModelIndex &child) const  override;

    Q_INVOKABLE int rowCount(const QModelIndex &parent = QModelIndex()) const  override;
    Q_INVOKABLE int columnCount(const QModelIndex &parent = QModelIndex()) const  override;
    Q_INVOKABLE bool hasChildren(const QModelIndex &parent = QModelIndex()) const override;

    Q_INVOKABLE QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
private:
    TreeItem* getTreeItem(const QModelIndex &indexToUse) const;
    QModelIndex indexOf(TreeItem* item) const;
    TreeItem* m_root;
};

#endif // TREEMODEL_H
