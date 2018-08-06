#include <jni.h>
#include <string>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avio.h>

}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_tongjiangsong_android_1ffmpeg_1demo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    char info[40000] = {0};

    struct URLProtocol *pup = NULL;

    struct URLProtocol **p_temp = &pup;
    avio_enum_protocols((void **) p_temp, 0);

    while ((*p_temp) != NULL) {
        sprintf(info, "%sInput: %s\n", info, avio_enum_protocols((void **) p_temp, 0));
    }
    pup = NULL;
    avio_enum_protocols((void **) p_temp, 1);
    while ((*p_temp) != NULL) {
        sprintf(info, "%sInput: %s\n", info, avio_enum_protocols((void **) p_temp, 1));
    }
    return env->NewStringUTF(info);
}
