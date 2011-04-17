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

//! Funcube Dongle source block.
/*! \ingroup block
 * 
 * This class provides a Funcube Dongle soure block by wrapping the
 * USB audio interface and the USG HID control interface of the Funcube
 * Dongle into one convenient source block.
 * 
 */
class fcd_source_c : public gr_hier_block2
{

public:
    fcd_source_c(const std::string device_name = ""); // FIXME: could be private
    ~fcd_source_c();
    
    //! Set frequency with Hz resolution.
    /*! \param freq The frequency in Hz
     * 
     * Set the frequency of the Funcube Dongle with 1 Hz resolution applying
     * the frequency correction set by set_freq_corr().
     * 
     * \see set_freq_kHz()
     * \todo Need to add Hz resolution to FCD API
     */
    void set_freq(int freq);
    
    //! Set frequency with kHz resolution.
    /*! \param freq The frequency in kHz
     * 
     * Sets the frequency of the Funcube Dongle with 1 kHz resolution
     * applying the frequency correction set by set_freq_corr().
     * 
     * \see set_freq()
     */
    void set_freq_khz(int freq);

    //! Set new frequency correction.
    /*! \param ppm The new frequency correction in parts per million
     * 
     * Version 1.1 FCDs (S/N 810 or later) need a correction of -12ppm.
     * Earlier FCDs need roughly -115ppm (default for gr-fcd).
     * 
     * Ref: http://www.funcubedongle.com/?p=617
     */
    void set_freq_corr(int ppm);
    
    //! Set DC offset correction.
    /*! \param dci DC correction for I component (-1.0 to 1.0)
     *  \param dcq DC correction for Q component (-1.0 to 1.0)
     * 
     * Set DC offset correction in the device. Default is 1.0.
     */
    void set_dc_corr(double dci, double dcq);
    
    //! Set IQ phase and gain balance.
    /*! \param gain The gain correction (-1.0 to 1.0)
     *  \param phase The phase correction (-1.0 to 1.0)
     * 
     * Set IQ phase and gain balance in the device. The default values
     * are 0.0 for phase and 1.0 for gain.
     */
    void set_iq_corr(double gain, double phase);

private:

    audio_source::sptr fcd;  /*!< The audio input source */
    int d_freq_corr;         /*!< The frequency correction in ppm */
};

#endif /* INCLUDED_FCD_SOURCE_C_H */
