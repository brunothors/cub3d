/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:03:09 by bnespoli          #+#    #+#             */
/*   Updated: 2025/06/02 17:01:50 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "cube.h"

int				init_game(t_cub *game);

void			init(t_cub *game);
void			init_struct_variables(t_validate *valid);

int				open_file(char *filename);
t_cub			*get_game(t_cub *game);
void			handle_error(char *error);

void			free_data(t_data *data);
void			free_memory(t_cub *game);

void			hook_key_press(mlx_key_data_t keydata, void *param);
void			hook_close(void *param);

void			process_input(t_cub *game);
bool			can_move_to(t_cub *game, float new_x, float new_y);
void			calculate_new_position(t_cub *game, float *new_x, float *new_y);

mlx_texture_t	*init_textures(char *path);
void			load_textures(t_cub *game);
uint32_t		get_texture_color(mlx_texture_t *texture, int y, int x);

void			draw_background(t_cub *game);

mlx_texture_t	*set_wall(t_cub *game, t_dda *ray);
void			draw_wall(t_dda *ray, t_cub *game, int pixel);

void			setup(t_cub *game);
void			update_image(t_cub *game);

void			draw_rays(t_cub *game);
void			calculate_delta_distance(t_dda *ray);
void			calculate_distance_to_side(t_dda *ray, t_cub *game);
void			dda_algorithm(t_dda *ray, t_cub *game);

void			draw_playerview(void *param);

void			parsing(int argc, char **argv, t_cub *game);
void			check_arguments(int argc);
void			check_extension(char *map_file);
void			check_map_content(t_validate *valid);
void			check_rgb(uint32_t *color, char *rgb_color,
					char *original, char c);
void			split_rgb(char ***rgb, char *rgb_color, char *original, char c);
uint32_t		convert_rgb(int r, int g, int b);
int				check_path(char *path);

void			data_processing(char *map_file, t_data *data);
void			read_textures_path(t_data *data, char *temp, int fd);

void			read_textures_path_aux(t_data *data, char *temp, char *line);
void			copy_texture_path(char **texture, char *path, char *mode,
					char *line);
void			trim_newline(char *str, char *line);
void			check_spaces(char *temp, char *mode, char *line);

void			count_map_size(t_data *data, char *temp, int fd);
void			read_and_copy_map_content(char *temp, int fd);
void			analyze_map_content(t_data *data, t_validate *valid);
void			get_max_columns(t_data *data);
void			get_max_lines(t_data *data);
int				check_invalid_char(char c);

void			surrounded_by_walls(t_data *data);
bool			check_diagonals(t_data *data, int line, int col);
bool			check_sides(t_data *data, int line, int col);

void			found_tabs(t_data *data);
char			*replace_tabs(char *line, int tabs);

#endif