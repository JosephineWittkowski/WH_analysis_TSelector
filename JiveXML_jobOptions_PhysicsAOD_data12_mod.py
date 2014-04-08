## RTT jOs run in RecExCommon environment
## (RecExCommon_links.sh), but this doesn't work
## with Cosmics, need to remove static db link
## with shell command:
import os
#### remove db link:
os.system('rm -rf sqlite200')
##
## this is a trick to over-ride .set_Value_and_Lock
## settings in readesd.py: The first setting counts !
##
from RecExConfig.RecFlags  import rec
from AthenaCommon.BeamFlags import jobproperties
from AthenaCommon.AthenaCommonFlags import athenaCommonFlags
from AthenaCommon.GlobalFlags import globalflags

## 'FilesInput' triggers full autoconfiguration, which
## replaces GEO and CONDDB setting by hand
#athenaCommonFlags.FilesInput.set_Value_and_Lock(['ESD_166198_10Ev.pool.root'])
## 'locking' seems unnecessary (moved from readesd.py to RecExCommon):
athenaCommonFlags.FilesInput=['AOD_23Mar12.pool.root']

## rarely not working for some data10_7TeV single-event ESDs, following
## switches to revert to manual settings:
#athenaCommonFlags.PoolESDInput.set_Value_and_Lock(['ESD_Cosmics_1.pool.root','ESD_Cosmics_2.pool.root'])
#globalflags.DetDescrVersion.set_Value_and_Lock('ATLAS-GEO-10-00-00')
#globalflags.ConditionsTag.set_Value_and_Lock('COMCOND-ES1PST-002-00') 
## force auto config off, necessary for some data10_7TeV ESDs
#rec.AutoConfiguration.set_Value_and_Lock([])

### all events:
#athenaCommonFlags.EvtMax.set_Value_and_Lock(-1)
### for test, some events:
athenaCommonFlags.EvtMax.set_Value_and_Lock(5)

rec.doJiveXML.set_Value_and_Lock(True)
rec.doCBNT.set_Value_and_Lock(False)
rec.doMonitoring.set_Value_and_Lock(False)
rec.doAOD.set_Value_and_Lock(False)
rec.doWriteAOD.set_Value_and_Lock(False)
rec.doHist.set_Value_and_Lock(False)
### comment-in the following line for
### pathena-setup to get single-event-ESD:
rec.doWriteESD.set_Value_and_Lock(True)

#### job options to retrieve spacepoints from ESDs
#### not done by default ! From Thijs Cornellisen
from InDetRecExample.InDetJobProperties import InDetFlags
jobproperties.InDetJobProperties.Enabled.set_Value_and_Lock(True)
InDetFlags.doSpacePointFormation.set_Value_and_Lock(True)
#### Following line mixes-up track associations !
#InDetFlags.disableInDetReco.set_Value_and_Lock(False)
#### Robust tracking jOs (in case SCT is off/safe mode)
#### from Carl Gwilliam:
#### not necessary anymore
##InDetFlags.doRobustReco.set_Value_and_Lock(True)

#### new 23Feb10: load full electronics calibration database
#### not done by default anymore. Info by G.Unal.
from LArConditionsCommon.LArCondFlags import larCondFlags
larCondFlags.LoadElecCalib.set_Value_and_Lock(True)

## old jOs for commissioning:
#include ("RecExCommission/readesd.py")
## better use standard jOs:
include("RecExCommon/RecExCommon_topOptions.py")
##
### only when patching AnalysisJiveXML tag (datatype duplication):
#theEventData2XML.DataTypes.remove( "JiveXML::MissingETRetriever/MissingETRetriever")
#theTrackRetriever.PriorityTrackCollection = "CombinedInDetTracks"
#theTrackRetriever.OutputLevel=DEBUG
theEventData2XML.DataTypes.remove( "JiveXML::JetRecJetRetriever/JetRecJetRetriever")
