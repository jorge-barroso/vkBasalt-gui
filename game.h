//
// Created by jorge on 8/21/22.
//

#ifndef VKBASALT_GUI_GAME_H
#define VKBASALT_GUI_GAME_H

#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QVariant>

struct Game
{
	QString title;
	QString path;
	long long game_id;

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

	static const QString values_separator;
	static const QString end_line_separator;

	friend QTextStream& operator<<(QTextStream& stream, const Game* game)
	{
		stream << game->title << values_separator << game->path << values_separator << game->game_id << values_separator
			   << game->cas_enabled << values_separator << game->cas_strength << values_separator << game->dls_enabled
			   << values_separator << game->dls_sharpness << values_separator << game->dls_denoise << values_separator
			   << game->fxaa_enabled << values_separator << game->fxaa_quality_subpixel << values_separator
			   << game->fxaa_edge_threshold << values_separator << game->fxaa_edge_threshold_min
			   << values_separator << game->smaa_enabled << values_separator << game->edge_detection_method
			   << values_separator << game->smaa_threshold << values_separator << game->smaa_search_steps
			   << values_separator << game->smaa_search_steps_diagonal << values_separator
			   << game->smaa_corner_rounding << values_separator << game->lut_enabled << values_separator
			   << game->lut_file_path;
		return stream;
	}

	friend QTextStream& operator>>(QTextStream& stream, Game* game)
	{
		QString contents{ stream.readLine() };
		QStringList values{ contents.split(values_separator) };

		game->title = values[0];
		game->path = values[1];
		game->game_id = values[2].toLongLong();
		game->cas_enabled = QVariant(values[3]).toBool();
		game->cas_strength = values[4].toFloat();
		game->dls_enabled = QVariant(values[5]).toBool();
		game->dls_sharpness = values[6].toFloat();
		game->dls_denoise = values[7].toFloat();
		game->fxaa_enabled = QVariant(values[8]).toBool();
		game->fxaa_quality_subpixel = values[9].toFloat();
		game->fxaa_edge_threshold = values[10].toFloat();
		game->fxaa_edge_threshold_min = values[11].toFloat();
		game->smaa_enabled = QVariant(values[12]).toBool();
		game->edge_detection_method = values[13];
		game->smaa_threshold = values[14].toFloat();
		game->smaa_search_steps = values[15].toFloat();
		game->smaa_search_steps_diagonal = values[16].toFloat();
		game->smaa_corner_rounding = values[17].toFloat();
		game->lut_enabled = QVariant(values[18]).toBool();
		game->lut_file_path = values[19];

		return stream;
	}
};

#endif //VKBASALT_GUI_GAME_H
