#include "materials.h"

Materials::Materials() {}

void Materials::setMaterialsIndex(int num)
{
    materials_index = num;
}

void Materials::setMaterialsMaxIndex(int element)
{
    materials_maxIndex = element;
}

void Materials::materials_clearVector()
{
    m_Materials_vector.clear();
    m_Materials_vector.assign(9,"");
    emit Materials_vectorChanged();
}

int Materials::getMaterialsIndex(int num)
{
    return materials_index +=num;
}

int Materials::getMaterialsMaxIndex()
{
    return materials_maxIndex;
}

QVector<QString> Materials::getMaterials_vector() const
{
    return m_Materials_vector;
}

void Materials::setMaterials_vector(const QVector<QString> &newMaterials_vector)
{
    if (m_Materials_vector == newMaterials_vector)
        return;
    m_Materials_vector = newMaterials_vector;
    emit Materials_vectorChanged();
}
