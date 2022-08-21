//
// Created by jorge on 8/21/22.
//

#ifndef VKBASALT_GUI_GAME_H
#define VKBASALT_GUI_GAME_H

#include <QString>

struct Game {
	QString title;
	QString path;

	bool cas_enabled;
	float cas_strength;

	bool dls_enabled;
	float dls_sharpness;
	float dls_denoise;

	bool fxaa_enabled;
	float fxaa_quality_subpixel;
	float fxaa_edge_threshold;
	float fxaa_edge_threshold_min;

	bool smaa_enabled;
	QString edge_detection_method;
	float smaa_threshold;
	float smaa_search_steps;
	float smaa_search_steps_diagonal;
	float smaa_corner_rounding;

	bool lut_enabled;
	QString lut_file_path;
};

#endif //VKBASALT_GUI_GAME_H
