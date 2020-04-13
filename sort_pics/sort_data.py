
####################################################################
# script to import data from different sources into defined structure

# Author: Michael Mink
# Date: 11/2019

# Dependencies:
# - exiftool

####################################################################

# import packages
import os
import exiftool
import glob

# predefined variables
dir_data_unsorted = '/media/pi/egon/data_all_unsorted/'
dir_data_sorted= '/media/pi/egon/data_sorted/'
folder_unknown_date = 'unknown_date'
daily_folder_suffix = '_dummy'
exif_Executable = '/usr/bin/exiftool'
exif_key_create_date = ':CreateDate'
pic_file_type = ('jpg', 'JPG', 'jpeg', 'JPEG', 'png', 'PNG')
vid_file_type = ('mp4', 'MP4', 'avi', 'AVI', 'MTS', 'MOV')


# ++++++++++++++++++++++++++++++
# create_date class
# ++++++++++++++++++++++++++++++
class create_date:
    def __init__(self):
        self.year = None
        self.month = None
        self.day = None

    def insert_date(self, year, month, day):
        self.year = year
        self.month = month
        self.day = day

    def get_date_string(self):
        if self.year is None and self.month is None and self.day is None:
            return None
        else:
            return '%s-%s-%s' % (self.year, self.month, self.day)

# create unknown date folder (if not exist)
path_unknown_date = os.path.join(dir_data_sorted, folder_unknown_date)
os.system('mkdir -p %s' % path_unknown_date)

# ++++++++++++++++++++++++++++++
# search directories recursively
# ++++++++++++++++++++++++++++++
for (path,dirs,files) in os.walk(dir_data_unsorted):
    # get files in directory
    for file in files:
        # check file if its a pic or a vid
        if file.endswith(pic_file_type) or file.endswith(vid_file_type):

            file_path = os.path.join(path, file)
            file_type = file.split('.')[-1]
            create_date_obj = create_date()

            # debug output
            print('processing file: %s' % (file_path))
            
            # read exif header
            with exiftool.ExifTool(executable_=exif_Executable) as et:
                exif_data = et.get_metadata(file_path)

            # get create_date entry from exif header (if available)
            create_date_tag = None
            for tag in exif_data:
                if exif_key_create_date in tag:
                    create_date_tag = tag
                    continue

            # if file has exif header and the create_date entry
            if create_date_tag in exif_data:
                create_datetime_raw = exif_data[create_date_tag]
                create_date_raw = create_datetime_raw.split(' ')[0]
                year = create_date_raw.split(':')[0]
                month = create_date_raw.split(':')[1]
                day = create_date_raw.split(':')[2]
                create_date_obj.insert_date(year, month, day)

            # if file has no exif header
            else:
                # in case its a whatsapp
                if ('IMG-' and '-WA' in file) or ('VID-' and '-WA' in file):
                    year = file.split('-')[1][0:4]
                    month = file.split('-')[1][4:6]
                    day = file.split('-')[1][6:8]
                    create_date_obj.insert_date(year, month, day)

            print('%s found --> %s, create date: %s' % (file_type, file_path, create_date_obj.get_date_string()))

            # if create_date is not found then cp file to unknown_date folder
            if create_date_obj.get_date_string() is None:
                os.system('cp -n %s %s' % (str(file_path), path_unknown_date))

            # ... otherwise proceed as usual
            else:
                # create yearly folder (if not exist)
                folder_year = os.path.join(dir_data_sorted, create_date_obj.year)
                os.system('mkdir -p %s' % (folder_year))

                # create daily folder (if not exist)
                folder_day_wo_suffix = os.path.join(dir_data_sorted, create_date_obj.year, create_date_obj.get_date_string())
                # if folder not exists then create default folder (w suffix)
                if len(glob.glob(os.path.join(folder_day_wo_suffix + '*'))) == 0:
                    folder_day = os.path.join(folder_day_wo_suffix + daily_folder_suffix)
                    os.system('mkdir -p %s' % (folder_day))
                elif len(glob.glob(os.path.join(folder_day_wo_suffix + '*'))) == 1:
                    folder_day = glob.glob(os.path.join(folder_day_wo_suffix + '*'))[0]
                elif len(glob.glob(os.path.join(folder_day_wo_suffix + '*'))) > 1:
                    print('more than one daily folders found!!!!!!')
                    exit(1)

                # copy to daily folder
                # if its a pic
                if file_type in pic_file_type:
                    os.system('cp -n %s %s' % (file_path, folder_day))
                # if its a vid
                elif file_type in vid_file_type:
                    # create vid dir if not exist
                    folder_day_vid = os.path.join(folder_day, 'vid')
                    os.system('mkdir -p %s' % (folder_day_vid))
                    os.system('cp -n %s %s' % (file_path, folder_day_vid))


                # rm files from unsorted folder
                # TODO ...


