/**
 * @file HomeView.qml
 * @brief Libertine default home view
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
import QtQuick 2.0
import Ubuntu.Components 1.1


Page {
    id: homeView
    title: i18n.tr("Classic Apps")

    head.actions: [
        Action {
	    iconName: "add"
	    onTriggered: mainView.state = "ADD_APPS"
	},
        Action {
	    iconName: "settings"
	    onTriggered: print("settings")
	}
    ]

    ContainerApps {
        id: containerApps
    }

    ListView {
        model: containerApps.appsForContainer
        delegate: Text {
            text: mainView.currentContainerId
        }
    }
}