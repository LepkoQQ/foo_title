/*
    Copyright 2005 - 2006 Roman Plasil
	http://foo-title.sourceforge.net
    This file is part of foo_title.

    foo_title is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.

    foo_title is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with foo_title; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#pragma once

#include "stdafx.h"
#include "utils.h"
#include "playCallback.h"

namespace fooManagedWrapper {

	private ref class CManagedInitQuit {
	public:
		CManagedInitQuit();

		void on_init();
		void on_quit();

	private:
		IPlayControl ^playControl;

	};

	class CInitQuit : public initquit {
	public:
		gcroot<CManagedInitQuit^> managedInitQuit;
		CPlayCallback *playCallback;

		void createPlayCallback();

		virtual void on_init();
		virtual void on_quit();
		virtual void on_system_shutdown();
	};

}