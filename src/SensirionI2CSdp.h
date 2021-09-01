/*
 * THIS FILE IS AUTOMATICALLY GENERATED
 *
 * I2C-Generator: 0.2.0
 * Yaml Version: 0.1.0
 * Template Version: 0.7.0-38-g217adaf
 */
/*
 * Copyright (c) 2021, Sensirion AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Sensirion AG nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SENSIRIONI2CSDP_H
#define SENSIRIONI2CSDP_H

#include <Wire.h>

#include <SensirionCore.h>

class SensirionI2CSdp {

  public:
    SensirionI2CSdp();
    /**
     * begin() - Initializes the SensirionI2CSdp class.
     *
     * @param serial Arduino stream object to be communicated with.
     *
     */
    void begin(TwoWire& i2cBus);

    /**
     * startContinuousMeasurementWithMassFlowTCompAndAveraging() - This command
     * starts continuous measurements with mass flow temperature compensation
     * and the average till read feature.
     *
     * @note The measurement command must only be sent once, if acknowledged.
     * The command must not be resent or other commands must not be sent until
     * the stop measurement command has been issued. After the start measurement
     * command is sent, the first measurement result is available after 8ms.
     * Small accuracy deviations (few % of reading) can occur during the next
     * 12ms. The measured values are updated every 0.5ms and can be read using
     * the read measurement interface.
     *
     * @return 0 on success, an error code otherwise
     */
    uint16_t startContinuousMeasurementWithMassFlowTCompAndAveraging(void);

    /**
     * startContinuousMeasurementWithMassFlowTComp() - This command starts
     * continuous measurements with mass flow temperature compensation.
     *
     * @note The measurement command must only be sent once, if acknowledged.
     * The command must not be resent or other commands must not be sent until
     * the stop measurement command has been issued. After the start measurement
     * command is sent, the first measurement result is available after 8ms.
     * Small accuracy deviations (few % of reading) can occur during the next
     * 12ms. The measured values are updated every 0.5ms and can be read using
     * the read measurement interface.
     *
     * @return 0 on success, an error code otherwise
     */
    uint16_t startContinuousMeasurementWithMassFlowTComp(void);

    /**
     * startContinuousMeasurementWithDiffPressureTCompAndAveraging() - This
     * command starts continuous measurements with differential pressure
     * temperature compensation and the average till read feature.
     *
     * @note The measurement command must only be sent once, if acknowledged.
     * The command must not be resent or other commands must not be sent until
     * the stop measurement command has been issued. After the start measurement
     * command is sent, the first measurement result is available after 8ms.
     * Small accuracy deviations (few % of reading) can occur during the next
     * 12ms. The measured values are updated every 0.5ms and can be read using
     * the read measurement interface.
     *
     * @return 0 on success, an error code otherwise
     */
    uint16_t startContinuousMeasurementWithDiffPressureTCompAndAveraging(void);

    /**
     * startContinuousMeasurementWithDiffPressureTComp() - This command starts
     * continuous measurements with differential pressure temperature
     * compensation.
     *
     * @note The measurement command must only be sent once, if acknowledged.
     * The command must not be resent or other commands must not be sent until
     * the stop measurement command has been issued. After the start measurement
     * command is sent, the first measurement result is available after 8ms.
     * Small accuracy deviations (few % of reading) can occur during the next
     * 12ms. The measured values are updated every 0.5ms and can be read using
     * the read measurement interface.
     *
     * @return 0 on success, an error code otherwise
     */
    uint16_t startContinuousMeasurementWithDiffPressureTComp(void);

    /**
     * stopContinuousMeasurement() - This command stops the continuous
     * measurement and puts the sensor in idle mode. It powers off the heater
     * and makes the sensor receptive to another command after 500us. The Stop
     * command is also required when switching between different continuous
     * measurement commands.
     *
     * @return 0 on success, an error code otherwise
     */
    uint16_t stopContinuousMeasurement(void);

    /**
     * triggerMeasurementWithMassFlowTCompAndAveraging() - This command triggers
     * a single shot measurement with mass flow temperature compensation.
     *
     * @note During a triggered measurement the sensor measures both
     * differential pressure and temperature. The measurement starts directly
     * after the command has been sent. The command needs to be repeated with
     * every measurement. During the 45ms that the sensor is measuring, no
     * command can be sent to the sensor. After the 45ms the result can be read
     * out and any command can be sent to the sensor.
     *
     * @return 0 on success, an error code otherwise
     */
    uint16_t triggerMeasurementWithMassFlowTCompAndAveraging(void);

    /**
     * triggerMeasurementWithDiffPressureTComp() - This command triggers a
     * single shot measurement with differential pressure temperature
     * compensation.
     *
     * @note During a triggered measurement the sensor measures both
     * differential pressure and temperature. The measurement starts directly
     * after the command has been sent. The command needs to be repeated with
     * every measurement. During the 45ms that the sensor is measuring, no
     * command can be sent to the sensor. After the 45ms the result can be read
     * out and any command can be sent to the sensor.
     *
     * @return 0 on success, an error code otherwise
     */
    uint16_t triggerMeasurementWithDiffPressureTComp(void);

    /**
     * readMeasurement() - After a start continuous measurement commands, the
     * measurement results can be read out at most every 0.5ms. After a
     * triggered measurement command, the results can be read out when the
     * sensor is finished with the measurement. The temperature and scale factor
     * don’t need to be read out (every time). The read sequence can be aborted
     * by a NACK and a STOP condition. The scale factor is for differential
     * pressure in Pascal.
     *
     * @param differentialPressure The digital calibrated differential pressure
     * signal read from the sensor is a signed integer number (two's complement
     * number). The integer value can be converted to the physical value by
     * dividing it by the scale factor. differential pressure in Pascal = sensor
     * output / scale factor
     *
     * @param temperature The digital calibrated temperature signal read from
     * the sensor is a signed integer number (two's complement number). The
     * integer value can be converted to the physical value by dividing it by a
     * scale factor of 200. temperature in °C = sensor output / 200
     *
     * @param scalingFactor Scaling factor differential pressure
     *
     * @return 0 on success, an error code otherwise
     */
    uint16_t readMeasurement(int16_t& differentialPressure,
                             int16_t& temperature, int16_t& scalingFactor);

    /**
     * enterSleepMode() - In sleep mode the sensor uses the minimum amount of
     * current. The mode can only be entered from idle mode, i.e. when the
     * sensor is not measuring. This mode is particularly useful for battery
     * operated devices. To minimize the current in this mode, the complexity of
     * the sleep mode circuit has been reduced as much as possible, which is
     * mainly reflected by the way the sensor exits the sleep mode. In sleep
     * mode the sensor cannot be soft reset.
     *
     * @note Triggered mode: the sleep command can be sent after the result have
     * been read out and the sensor is in idle mode. Continuous mode: the sleep
     * command can be sent after a stop continuous measurement command has been
     * issued and the sensor is in idle mode.
     *
     * @return 0 on success, an error code otherwise
     */
    uint16_t enterSleepMode(void);

    /**
     * exitSleepMode() - Exit sleep mode. See the data sheet for more detailed
     * information
     *
     * @return error code, but you can ignore a NACK error as that command is not acknowledged
     */
    uint16_t exitSleepMode(void);

    /**
     * prepareProductIdentifier() - Prepare for reading the product identifier
     * and sensor serial number.
     *
     * @return 0 on success, an error code otherwise
     */
    uint16_t prepareProductIdentifier(void);

    /**
     * readProductIdentifier() - Read the product identifier and serial number
     * of the sensor.
     *
     * @note Make sure to call 'prepare product identifier' immediately before.
     *
     * @param productNumber 32 bit unique product and revision number. The
     * number is listed in the datasheet. Note that the last 8 bits are the
     * revision number and can be subject to change.
     *
     * @param serialNumber 64-bit unique serial number
     *
     * @return 0 on success, an error code otherwise
     */
    uint16_t readProductIdentifier(uint32_t& productNumber,
                                   uint8_t serialNumber[],
                                   uint8_t serialNumberSize);

  private:
    TwoWire* _i2cBus = nullptr;
};

#endif /* SENSIRIONI2CSDP_H */
