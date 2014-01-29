/*
 * This software has been licensed to the Centre of Speech Technology, KTH
 * by AT&T Corp. and Microsoft Corp. with the terms in the accompanying
 * file BSD.txt, which is a BSD style license.
 *
 *    "Copyright (c) 1987-1990  AT&T, Inc.
 *    "Copyright (c) 1986-1990  Entropic Speech, Inc.
 *    "Copyright (c) 1990-1991  Entropic Research Laboratory, Inc.
 *                   All rights reserved"
 */

 /* this is an older version of the waves tracks.h needed for this version
    of formant
 */

typedef short sample_t;
typedef float storage_t;

typedef struct { /* structure of a DP lattice node for formant tracking */
    short ncand; /* # of candidate mappings for this frame */
    short **cand;      /* pole-to-formant map-candidate array */
    short *prept;	 /* backpointer array for each frame */
    double *cumerr; 	 /* cum. errors associated with each cand. */
} form_t;

typedef struct {   /* structure to hold raw LPC analysis data */
    double rms;    /* rms for current LPC analysis frame */
    double rms2;    /* rms for current F0 analysis frame */
    double f0;     /* fundamental frequency estimate for this frame */
    double pv;		/* probability that frame is voiced */
    double change; /* spec. distance between current and prev. frames */
    short npoles; /* # of complex poles from roots of LPC polynomial */
    double *freq;  /* array of complex pole frequencies (Hz) */
    double *band;  /* array of complex pole bandwidths (Hz) */
} pole_t;

typedef struct Sound {
    size_t samprate;
    size_t nchannels;
    int length;
    storage_t *blocks;

    pole_t **pole;
} Sound;

Sound *Snack_NewSound(int rate, int nchannels);
void Snack_DeleteSound(Sound *s);
void LoadSound(Sound *s, short *samples, size_t len);
void formantCmd(Sound *s);
