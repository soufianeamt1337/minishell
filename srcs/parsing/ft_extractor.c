/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extractor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 02:13:21 by samajat           #+#    #+#             */
/*   Updated: 2022/04/25 00:22:32 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     is_delimter (char c, char *delimter)
{
    int i;

    i = 0;
    while (delimter[i])
    {
        if (c == delimter[i])
            return (1);
        i++;
    }
    return (0);
}

int    extract_norm(t_cmd *cmd, char  *str, int   *i)
{
    char    *s;
    int     start;

    start = *i;
    if (!str || !str[*i])
        return (0);
    if (ft_is_quote(str[*i]) || ft_is_redi(str[*i]))
        return (0);
    while (str[*i] && !is_delimter(str[*i], " <>"))
        (*i)++;
    s = ft_substr(str, start, *i - start);
    if (!s)
        chstatus (MEMORY_LACK, NULL, 30);
    while (ft_ispace(str[*i]))
        (*i)++;
    if (!*data.status.exit_code && s[0] && ft_strcmp (s, ""))
    {
        ft_lstadd_back(&cmd->ex_elements, ft_lstnew((char *)s, CHAR));
        if (*data.status.exit_code)
            return (0);
    }
    else
    {
        free(s);
    }
    return (1);
}

//you should handle the quote type are not the same reflex

//Quote keeper && quote ridder
int    extract_quote(t_cmd *cmd, char  *str, int   *i)
{
    // int quoting_type;
    int start;
    char    *s;

    start = *i;
    while (str[*i] && (str[*i] == '\'' || str[*i] == '\"'))
        (*i)++;
    while (str[*i] && str[*i] != '\'' && str[*i] != '\"')
        (*i)++;
    while (str[*i] && (str[*i] == '\'' || str[*i] == '\"'))
        (*i)++;
    s = ft_substr(str, start, *i - start);
    if (!s)
        chstatus (MEMORY_LACK, NULL, 30);
    if (!*data.status.exit_code && s[0] && ft_strcmp (s, ""))
    {
        ft_lstadd_back(&cmd->ex_elements, ft_lstnew((char *)s, CHAR));
        if (*data.status.exit_code)
            return (0);
    }
    else
    {
        free(s);
        return (0);
    }
    return (1);
}

int    extract_redir(t_cmd *cmd, char *str, int *i)
{
    char    *s;

    if((str[*i] == '>' && str[(*i) + 1] == '>') || (str[*i] == '<' && str[(*i) + 1] == '<'))
    {
        s = ft_substr(str, *i, 2);
        if (!s)
            chstatus (MEMORY_LACK, NULL, 30);
        (*i)+=2;
        if (!*data.status.exit_code && s[0] && ft_strcmp (s, ""))
        {
            ft_lstadd_back(&cmd->ex_elements, ft_lstnew((char *)s, CHAR));
            if (*data.status.exit_code)
                return (0);
        }
        else
        {
            free(s);
        }
        return (1);
    }
    else if(str[*i] == '>'|| str[*i] == '<')
    {
        s = ft_substr(str, *i, 1);
        if (!s)
            chstatus (MEMORY_LACK, NULL, 30);
        (*i)++;
        if (!*data.status.exit_code && s[0] && ft_strcmp (s, ""))
        {
            ft_lstadd_back(&cmd->ex_elements, ft_lstnew((char *)s, CHAR));
            if (*data.status.exit_code)
                return (0);
        }
        else
        {
            free(s);
        }
        return (1);
    }
    return (0);
}

void    ft_extract_data(t_cmd *cmd, char    *command)
{
    
    int         a;

    if (!(command + data.e) && !command[data.e])
        return ;
    if (extract_norm(cmd, command, &data.e))
        a = 0;
    else if (extract_redir(cmd, command, &data.e))
        a = 0;
    else if (extract_quote(cmd, command, &data.e))
        a = 0;
    if (command[data.e])
    {
        ft_extract_data(cmd, command);
        if (*data.status.exit_code)
            return ;
    }
}