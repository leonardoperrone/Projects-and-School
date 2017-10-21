import { TemplateRef } from "@angular/core";
export declare class ColumnComponent {
    text: string;
    dataIndex: string;
    hidden: boolean;
    dataType: string;
    summaryType: string;
    summaryCaption: string;
    headerTemplate: TemplateRef<any>;
    bodyTemplate: TemplateRef<any>;
}
