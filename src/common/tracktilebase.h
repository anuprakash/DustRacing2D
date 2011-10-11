// This file is part of Dust Racing (DustRAC).
// Copyright (C) 2011 Jussi Lind <jussi.lind@iki.fi>
//
// DustRAC is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// DustRAC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with DustRAC. If not, see <http://www.gnu.org/licenses/>.

#ifndef TRACKTILEBASE_H
#define TRACKTILEBASE_H

#include <QPoint>
#include <QPointF>
#include <QString>

class TrackData;

//! Base class for track tiles used in the editor and in the game.
class TrackTileBase
{
public:

    //! Direction to the next tile in the route.
    enum RouteDirection {RD_NONE = 0, RD_LEFT, RD_RIGHT, RD_UP, RD_DOWN};

    //! Possible profiles of a tile.
    enum TileProfile {TP_FLAT = 0, TP_HILL, TP_GORGE};

    //! Constructor.
    //! \param trackData Pointer to the "parent" TrackData.
    //! \param location Location (coordinates) in the track scene.
    //! \param matrixLocation Location in the tile matrix.
    //! \param type Type of the tile. See setType().
    TrackTileBase(TrackData * trackData, QPointF location, QPoint matrixLocation,
                  const QString & type = "clear");

    //! Destructor.
    virtual ~TrackTileBase();

    //! Return pointer to the "parent" track data.
    TrackData * trackData() const;

    //! Get location in world / scene.
    virtual QPointF location() const;

    //! Get location in the tile matrix.
    virtual QPoint matrixLocation() const;

    //! Set index in the route vector.
    virtual void setRouteIndex(int index);

    //! Get route index, return -1 if not set.
    int routeIndex() const;

    //! Set type: "corner", "straight", "grass", "finish", "clear"..
    void setTileType(const QString & type);

    //! Get type
    const QString & tileType() const;

    //! Set direction towards next tile in the route.
    void setRouteDirection(TrackTileBase::RouteDirection direction);

    //! Get direction towards next tile in the route.
    TrackTileBase::RouteDirection routeDirection() const;

    //! Set profile
    void setProfile(TileProfile profile);

    //! Get profile
    TileProfile profile() const;

private:

    //! Index in the route vector.
    int m_routeIndex;

    //! Type string.
    QString m_tileType;

    //! Location in the world / scene.
    QPointF m_location;

    //! Location in the tile matrix.
    QPoint m_matrixLocation;

    //! Pointer to the "parent" track data.
    TrackData * m_trackData;

    //! Direction towards the next tile in the route.
    RouteDirection m_routeDirection;

    //! Profile of the tile.
    TileProfile m_profile;
};

#endif // TRACKTILEBASE_H