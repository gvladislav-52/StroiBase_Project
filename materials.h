#ifndef MATERIALS_H
#define MATERIALS_H

#include <QObject>

class Materials: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector<QString> Materials_vector READ getMaterials_vector WRITE setMaterials_vector NOTIFY Materials_vectorChanged FINAL)
public:
    Materials();
    QVector<QString> getMaterials_vector() const;
signals:
    void Materials_vectorChanged();
public slots:
    int getMaterialsIndex(int num);
    int getMaterialsMaxIndex();
    void setMaterialsIndex(int num);
    void setMaterialsMaxIndex(int element);
    void materials_clearVector();
    void setMaterials_vector(const QVector<QString> &newMaterials_vector);
private:
    QVector<QString> m_Materials_vector;
    int materials_index = 0;
    int materials_maxIndex;
};


#endif // MATERIALS_H
