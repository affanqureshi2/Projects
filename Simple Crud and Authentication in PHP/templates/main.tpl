{$header}
{$content}
<!--
{if $page_1 eq '1'}
{$edit}
{elseif $page_1 eq '2'}
{$view}
{elseif $page_1 eq '3'}
{$logout}
{else}
{$login}
{/if}
-->
{include file="footer.tpl"}