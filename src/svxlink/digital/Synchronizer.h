/**
@file	 Synchronizer.h
@brief   A_brief_description_for_this_file
@author  Tobias Blomberg / SM0SVX
@date	 2010-

A_detailed_description_for_this_file

\verbatim
<A brief description of the program or library this file belongs to>
Copyright (C) 2003-2010 Tobias Blomberg / SM0SVX

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
\endverbatim
*/

/** @example Synchronizer_demo.cpp
An example of how to use the Synchronizer class
*/


#ifndef SYNCHRONIZER_INCLUDED
#define SYNCHRONIZER_INCLUDED


/****************************************************************************
 *
 * System Includes
 *
 ****************************************************************************/

#include <vector>
#include <sigc++/sigc++.h>


/****************************************************************************
 *
 * Project Includes
 *
 ****************************************************************************/

#include <AsyncAudioSink.h>


/****************************************************************************
 *
 * Local Includes
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Forward declarations
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Namespace
 *
 ****************************************************************************/

//namespace MyNameSpace
//{


/****************************************************************************
 *
 * Forward declarations of classes inside of the declared namespace
 *
 ****************************************************************************/

  

/****************************************************************************
 *
 * Defines & typedefs
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Exported Global Variables
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Class definitions
 *
 ****************************************************************************/

/**
@brief	A_brief_class_description
@author Tobias Blomberg / SM0SVX
@date   2008-

A_detailed_class_description

\include Synchronizer_demo.cpp
*/
class Synchronizer : public Async::AudioSink, public sigc::trackable
{
  public:
    /**
     * @brief 	Constuctor
     */
    Synchronizer(unsigned baudrate, unsigned sample_rate=INTERNAL_SAMPLE_RATE);
  
    /**
     * @brief 	Destructor
     */
    ~Synchronizer(void);
  
    /**
     * @brief 	A_brief_member_function_description
     * @param 	param1 Description_of_param1
     * @return	Return_value_of_this_member_function
     */
    int writeSamples(const float *samples, int len);
    void flushSamples(void);
    
    sigc::signal<void, std::vector<bool>&> bitsReceived;

  protected:
    
  private:
    const unsigned baudrate;
    const unsigned sample_rate;
    const unsigned shift_pos;
    unsigned pos;
    std::vector<bool> bitbuf;
    bool was_mark;
    bool last_stored_was_mark;
    int err;

    Synchronizer(const Synchronizer&);
    Synchronizer& operator=(const Synchronizer&);
    
};  /* class Synchronizer */


//} /* namespace */

#endif /* SYNCHRONIZER_INCLUDED */



/*
 * This file has not been truncated
 */
