/**
 * Interface library to medipix Labview system.
 * 
 * Matthew Pearson
 * Nov 2011
 */

#ifndef MPX_LOW_H
#define MPX_LOW_H

#include <asynOctetSyncIO.h>

extern int mpxSet(const char *command, const char *value);
extern int mpxGet(const char *command, char *value);
extern int mpxCmd(const char *command);
extern int mpxData(unsigned int *data);
extern int mpxConnect(const char *host, int commandPort, int dataPort);
extern int mpxIsConnected(int *conn);
extern int mpxDisconnect(void);

/* Fixed protocol names*/
#define MPX_HEADER "MPX"
#define MPX_SET "SET"
#define MPX_GET "GET"
#define MPX_CMD "CMD"
#define MPX_DATA_HEADER "CMD"
#define MPX_DATA_ACQ_HDR "HDR"
#define MPX_DATA_12 "12B"
#define MPX_DATA_24 "24B"
#define MPX_GENERIC_IMAGE "IMG"
#define MPX_PROFILE_12 "P12"
#define MPX_PROFILE_24 "P24"
#define MPX_GENERIC_PROFILE "PRF"
#define MPX_QUAD_DATA "MQ1"
#define MPX_MSG_LEN_DIGITS 10
#define MPX_MSG_DATATYPE_LEN 3

#define MPX_MAXLINE 256
#define MPX_IMG_HDR_LEN 256
#define MPX_ACQUISITION_HEADER_LEN 2044

#define MPX_X_SIZE 256
#define MPX_Y_SIZE 256
#define MPX_IMAGE_PIXELS 65536
#define MPX_IMAGE_BYTES MPX_IMAGE_PIXELS * 2 // 16 bit pixels
// size of buffer for image frame body including leading comma
#define MPX_IMG_FRAME_LEN MPX_IMG_HDR_LEN + MPX_IMAGE_BYTES + MPX_MSG_DATATYPE_LEN + 2
#define MPX_IMG_FRAME_LEN24 MPX_IMG_HDR_LEN + MPX_IMAGE_BYTES * 2 + MPX_MSG_DATATYPE_LEN + 2 // 32 bit pixels in 12 bit mode
#define MAX_BUFF_MERLIN_QUAD 530000
#define MAX_BUFF_UOM 5300000  // TODO verify has this got an extra 0 on it??

// error definitions
#define MPX_OK 0    			/*Ok*/
#define MPX_ERR 1               /*Unknown Error*/
#define MPX_ERR_CMD 2   		/*Command not known.*/
#define MPX_ERR_PARAM 3         /*Param out of range.*/
#define MPX_ERR_BUSY 4          /*The controller is busy and not accepting commands */
#define MPX_ERR_CONN 100  		/*Not connected to detector.*/
#define MPX_ERR_WRITE 101 		/*Error writing to socket.*/
#define MPX_ERR_READ 102 		/*Error reading from socket.*/
#define MPX_ERR_LEN 103 		/*Length of command and value too long, or NULL*/
#define MPX_ERR_DATA 110 		/*Data formatting error.*/
#define MPX_ERR_UNEXPECTED 111 	/*unexpected response from labview */

// variables - Acqusition and Trigger control
#define MPXVAR_GETSOFTWAREVERSION 		"SOFTWAREVERSION"
#define MPXVAR_DETECTORSTATUS 			"DETECTORSTATUS"
#define MPXVAR_NUMFRAMESTOACQUIRE 		"NUMFRAMESTOACQUIRE"
#define MPXVAR_ACQUISITIONTIME 			"ACQUISITIONTIME"
#define MPXVAR_ACQUISITIONPERIOD 		"ACQUISITIONPERIOD"
#define MPXVAR_TRIGGERSTART				"TRIGGERSTART"
#define MPXVAR_TRIGGERSTOP 				"TRIGGERSTOP"
#define MPXVAR_NUMFRAMESPERTRIGGER 		"NUMFRAMESPERTRIGGER"
#define MPXVAR_COUNTERDEPTH		 		"COUNTERDEPTH"
#define MPXVAR_ENABLECOUNTER1           "ENABLECOUNTER1"
#define MPXVAR_CONTINUOUSRW             "CONTINUOUSRW"
#define MPXVAR_ROI                      "ROI"
#define MPXVAR_ENABLEBACKROUNDCORR      "BCKGRNDCORRECTION"
#define MPXVAR_BACKGROUNDCOUNT          "BCKGRND"
#define MPXVAR_ENABLEIMAGEAVERAGE       "IMGAVERAGE"
#define MPXVAR_IMAGESTOSUM              "IMAGESTOSUM"

// variables Threshold Scan Control
#define MPXVAR_THSSCAN 					"THSCAN"
#define MPXVAR_THWINDOWMODE 			"THWINDOWMODE"
#define MPXVAR_THWINDOWSIZE 			"THWINDOWSIZE"
#define MPXVAR_THSTART 					"THSTART"
#define MPXVAR_THSTOP 					"THSTOP"
#define MPXVAR_THSTEP	 				"THSTEP"
#define MPXVAR_THRESHOLD0				"THRESHOLD0"
#define MPXVAR_THRESHOLD1				"THRESHOLD1"
#define MPXVAR_OPERATINGENERGY			"OPERATINGENERGY"

// commands
#define MPXCMD_STARTACQUISITION         "STARTACQUISITION"
#define MPXCMD_STOPACQUISITION          "STOPACQUISITION"
#define MPXCMD_THSCAN                   "THSCAN"
#define MPXCMD_SOFTWARETRIGGER          "SWTRIGGER"
#define MPXCMD_RESET                    "RESET"
#define MPXCMD_PROFILECONTROL           "PROFILES"
#define MPXCMD_PROFILES                 "PROFILES"
#define MPXCMD_BACKGROUNDACQUIRE        "BCKGRND"


// Bits in the PROFILES selection mask
#define MPXPROFILES_IMAGE               1
#define MPXPROFILES_XPROFILE            2
#define MPXPROFILES_YPROFILE            4
#define MPXPROFILES_SUM                 8


#endif /* MPX_LOW_H */
