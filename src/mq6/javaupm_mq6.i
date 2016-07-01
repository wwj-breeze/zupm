%module javaupm_mq6
%include "../upm.i"

%{
    #include "mq6.hpp"
%}

%include "mq6.hpp"

%pragma(java) jniclasscode=%{
    static {
        try {
            System.loadLibrary("javaupm_mq6");
        } catch (UnsatisfiedLinkError e) {
            System.err.println("Native code library failed to load. \n" + e);
            System.exit(1);
        }
    }
%}