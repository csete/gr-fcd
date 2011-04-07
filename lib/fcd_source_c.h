/* -*- c++ -*- */
/*
 * Copyright 2011 Free Software Foundation, Inc.
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_FCD_SOURCE_C_H
#define INCLUDED_FCD_SOURCE_C_H

#include <gr_hier_block2.h>
#include <gr_audio_source.h>

class fcd_source_c;


typedef boost::shared_ptr<fcd_source_c> fcd_source_c_sptr;


/*!
 * \brief Return a shared_ptr to a new instance of fcd_source_c.
 *
 * To avoid accidental use of raw pointers, howto_square2_ff's
 * constructor is private.  howto_make_square2_ff is the public
 * interface for creating new instances.
 */
fcd_source_c_sptr fcd_make_source_c(const std::string device_name = "");

/*!
 * \brief Funcube Dongle source block.
 * \ingroup block
 */
class fcd_source_c : public gr_hier_block2
{

public:
    fcd_source_c(const std::string device_name = ""); // FIXME: should be private
    ~fcd_source_c();

private:
    audio_source::sptr fcd;  /*!< The audio input source */

};

#endif /* INCLUDED_FCD_SOURCE_C_H */
