#ifndef LIBASM_H
# define LIBASM_H

typedef struct		s_list
{
	void		*data;
	struct s_list	*next;
}					t_list;

void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstnew(void *content);
int	ft_lstsize(t_list *lst);
int 	ft_list_size(t_list *list);
void	ft_list_push_front(t_list **begin_list, void *data);
void	ft_lstprinter(t_list *lst);
void	ft_hello(void *a, void *b);

#endif
