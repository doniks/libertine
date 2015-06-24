/**
 * @file ContainerManager.h
 * @brief Threaded Libertine container manager
 */
/*
 * Copyright 2015 Canonical Ltd
 *
 * Libertine is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3, as published by the
 * Free Software Foundation.
 *
 * Libertine is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef CONTAINER_CONTAINERMANAGER_H_
#define CONTAINER_CONTAINERMANAGER_H_

#include "libertine/libertine_lxc_manager_wrapper.h"

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QThread>

class ContainerManagerWorker
: public QThread
{
  Q_OBJECT

public:
  enum class ContainerAction
  : int
  {
    Create,
    Destroy,
    Install,
    Update
  };

public:
  ContainerManagerWorker(ContainerAction container_action,
                         QString const& container_id);
  ContainerManagerWorker(ContainerAction container_action,
                         QString const& container_id,
                         QString const& package_name);
  ~ContainerManagerWorker();

protected:
  void run() Q_DECL_OVERRIDE;

private:
  void createContainer(QString const& container_id);
  void destroyContainer(QString const& container_id);
  void installPackage(QString const& container_id, QString const& package_name);
  void updateContainer(QString const& container_id);

private:
  ContainerAction container_action_;
  QString container_id_;
  QString package_name_;

signals:
  void finished();
};

#endif /* CONTAINER_CONTAINERMANAGER_H_ */