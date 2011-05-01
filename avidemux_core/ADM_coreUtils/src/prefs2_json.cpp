// automatically generated by admSerialization.py, do not edit!
#include "ADM_default.h"
#include "ADM_paramList.h"
#include "ADM_coreJson.h"
#include "prefs2.h"
bool  my_prefs_struct_jserialize(const char *file, const my_prefs_struct *key){
admJson json;
json.addNode("features");
json.addBool("swap_if_A_greater_than_B",key->features.swap_if_A_greater_than_B);
json.addBool("saveprefsonexit",key->features.saveprefsonexit);
json.addBool("ignoresavedmarkers",key->features.ignoresavedmarkers);
json.addBool("use_odml",key->features.use_odml);
json.addBool("use_systray",key->features.use_systray);
json.addBool("reuse_2pass_log",key->features.reuse_2pass_log);
json.addBool("audiobar_uses_master",key->features.audiobar_uses_master);
json.addUint32("threading_lavc",key->features.threading_lavc);
json.addUint32("cpu_caps",key->features.cpu_caps);
json.addBool("mpeg_no_limit",key->features.mpeg_no_limit);
json.addBool("alternate_mp3_tag",key->features.alternate_mp3_tag);
json.addBool("vdpau",key->features.vdpau);
json.endNode();
json.addNode("lastfiles");
json.addString("lastdir_read",key->lastfiles.lastdir_read);
json.addString("lastdir_write",key->lastfiles.lastdir_write);
json.addString("file1",key->lastfiles.file1);
json.addString("file2",key->lastfiles.file2);
json.addString("file3",key->lastfiles.file3);
json.addString("file4",key->lastfiles.file4);
json.endNode();
json.addUint32("message_level",key->message_level);
json.addNode("audio_device");
json.addString("audiodevice",key->audio_device.audiodevice);
json.addString("alsa_device",key->audio_device.alsa_device);
json.endNode();
json.addUint32("videodevice",key->videodevice);
json.addNode("priority");
json.addUint32("encoding",key->priority.encoding);
json.addUint32("indexing",key->priority.indexing);
json.addUint32("playback",key->priority.playback);
json.endNode();
json.addNode("Default");
json.addUint32("postproc_type",key->Default.postproc_type);
json.addUint32("postproc_value",key->Default.postproc_value);
json.addUint32("downmixing",key->Default.downmixing);
json.endNode();
json.addUint32("mpegsplit_autosplit",key->mpegsplit_autosplit);
return json.dumpToFile(file);
};
bool  my_prefs_struct_jdeserialize(const char *file, const ADM_paramList *tmpl,my_prefs_struct *key){
admJsonToCouple json;
CONFcouple *c=json.readFromFile(file);
if(!c) {ADM_error("Cannot read json file");return false;}
bool r= ADM_paramLoadPartial(c,tmpl,key);
delete c;
return r;
};
