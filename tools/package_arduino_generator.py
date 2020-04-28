import os
import hashlib
import json
import tarfile


def set_permissions(tarinfo):
    if tarinfo.name == 'Teknikio_nRF52_Arduino/tools/adafruit-nrfutil/macos/adafruit-nrfutil':
        print tarinfo.mode
        tarinfo.mode = 0b1111111111
    return tarinfo

# Be careful, if you're using this script on windows, you MUST use \ and you MUST double each

PATH_FOLDER = 'C:\\Users\\fabie\\Documents\\GitHub\\Teknikio_nRF52_Arduino\\'
PATH_BASE = 'Teknikio_nRF52_Arduino\\'
PATH_ADAFRUIT_TOOL= 'tools\\adafruit-nrfutil\\macos\\adafruit-nrfutil'
FILE_NAME = 'Teknikio_nRF52_Arduino.tar'
VERSION = '0.15.8'
DESTINATION_FOLDER = 'C:\\Users\\fabie\\Documents\\GitHub\\Githubio\\arduino-support-packages\\'




os.system("del /f " + DESTINATION_FOLDER + FILE_NAME)
# Compress the archive
with tarfile.open(DESTINATION_FOLDER + FILE_NAME, "w:") as tar:
        tar.add(PATH_FOLDER, arcname=PATH_BASE, filter=set_permissions)
  
# Compute the MD5
md5_checksum = hashlib.md5(open(DESTINATION_FOLDER + FILE_NAME,'rb').read()).hexdigest()

file_size = os.stat(DESTINATION_FOLDER + FILE_NAME).st_size


# Create the new JSON file


with open("C:\\Users\\fabie\\Documents\\GitHub\\Githubio\\arduino-support-packages\\package_teknikio_index.json",'rb') as json_file:
	data = json.load(json_file)
	data['packages'][0]['platforms'][0]['checksum'] = u'MD5:'+ str(md5_checksum)
	data['packages'][0]['platforms'][0]['size'] = u''+ str(file_size)
	version = data['packages'][0]['platforms'][0]['version'] = u''+ VERSION

with open("C:\\Users\\fabie\\Documents\\GitHub\\Githubio\\arduino-support-packages\\package_teknikio_index.json",'w') as outfile:
	json.dump(data,outfile, indent=2)


print "End of the script"
