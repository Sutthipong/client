/*
 * Copyright (C) by Hannah von Reth <hannah.vonreth@owncloud.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 */
#pragma once

#include "owncloudlib.h"

#include <QObject>

namespace OCC {

class AbstractNetworkJob;

class OWNCLOUDSYNC_EXPORT JobQueue : public QObject
{
    Q_OBJECT
public:
    JobQueue();

    void block(bool block);
    bool isBlocked() const;
    bool retry(AbstractNetworkJob *job);
    bool queue(AbstractNetworkJob *job);
    void clear();

private:
    bool needsRetry(AbstractNetworkJob *job) const;
    bool _blocked = false;
    std::vector<QPointer<AbstractNetworkJob>> _jobs;
};

}
