//-----------------------------------------------------------------------------
//
//	SensorBinary.h
//
//	Implementation of the Z-Wave COMMAND_CLASS_SENSOR_BINARY
//
//	Copyright (c) 2010 Mal Lansell <openzwave@lansell.org>
//
//	SOFTWARE NOTICE AND LICENSE
//
//	This file is part of OpenZWave.
//
//	OpenZWave is free software: you can redistribute it and/or modify
//	it under the terms of the GNU Lesser General Public License as published
//	by the Free Software Foundation, either version 3 of the License,
//	or (at your option) any later version.
//
//	OpenZWave is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU Lesser General Public License for more details.
//
//	You should have received a copy of the GNU Lesser General Public License
//	along with OpenZWave.  If not, see <http://www.gnu.org/licenses/>.
//
//-----------------------------------------------------------------------------

#ifndef _SensorBinary_H
#define _SensorBinary_H

#include "command_classes/CommandClass.h"

namespace OpenZWave
{
	namespace Internal
	{
		namespace CC
		{

			/** \brief Implements COMMAND_CLASS_SENSOR_BINARY (0x30), a Z-Wave device command class.
			 * \ingroup CommandClass
			 */
			class SensorBinary: public CommandClass
			{
				public:
					static CommandClass* Create(uint32 const _homeId, uint8 const _nodeId)
					{
						return new SensorBinary(_homeId, _nodeId);
					}
					virtual ~SensorBinary()
					{
					}

					static uint8 const StaticGetCommandClassId()
					{
						return 0x30;
					}
					static string const StaticGetCommandClassName()
					{
						return "COMMAND_CLASS_SENSOR_BINARY";
					}

					// From CommandClass
					virtual void ReadXML(TiXmlElement const* _ccElement) override;
					virtual void WriteXML(TiXmlElement* _ccElement) override;
					virtual bool RequestState(uint32 const _requestFlags, uint8 const _instance, Driver::MsgQueue const _queue) override;
					virtual bool RequestValue(uint32 const _requestFlags, uint16 const _index, uint8 const _instance, Driver::MsgQueue const _queue) override;
					virtual uint8 const GetCommandClassId() const override
					{
						return StaticGetCommandClassId();
					}
					virtual string const GetCommandClassName() const override
					{
						return StaticGetCommandClassName();
					}
					virtual bool HandleMsg(uint8 const* _data, uint32 const _length, uint32 const _instance = 1) override;
					virtual void SetValueBasic(uint8 const _instance, uint8 const _value) override;

				protected:
					virtual void CreateVars(uint8 const _instance) override;

				private:
					SensorBinary(uint32 const _homeId, uint8 const _nodeId) :
							CommandClass(_homeId, _nodeId)
					{
					}
					map<uint8, uint8> m_sensorsMap;
			};
		} // namespace CC
	} // namespace Internal
} // namespace OpenZWave

#endif

