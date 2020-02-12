/*
    AleePlayer: Music player in Qt
    Copyright (C) 2020 Alee Productions

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "library.h"

Library::Library(QObject *parent)
    : QAbstractListModel(parent)
{
}

int Library::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return 3;

}

QVariant Library::data(const QModelIndex &index, int role) const
{

    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole) {
      switch (index.row()) {
        case 0:
          return "Item 1";
        case 1:
          return "Item 2";
        case 2:
          return "Item 3";
      }
    }

    return QVariant();
}
